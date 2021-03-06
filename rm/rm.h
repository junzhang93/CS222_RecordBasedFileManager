#ifndef _rm_h_
#define _rm_h_

#include <string>
#include <vector>
#include <unordered_map>
#include "../rbf/rbfm.h"
#include "../ix/ix.h"

using namespace std;

#define RM_EOF (-1)  // end of a scan operator

class RelationManager;

struct Index {
    string indexName;
    string attributeName;
    string tableName;
};

// RM_ScanIterator is an iterator to go through tuples
class RM_ScanIterator {
    friend class RelationManager;

public:
    RM_ScanIterator() {}

    ~RM_ScanIterator() {}

    // "data" follows the same format as RelationManager::insertTuple()
    RC getNextTuple(RID &rid, void *data) {
        return (rbfm_scanIterator.getNextRecord(rid, data) == RBFM_EOF) ? RM_EOF : SUCCESS;
    }

    RC close() { return rbfm_scanIterator.close(); }

private:
    RBFM_ScanIterator rbfm_scanIterator;
};

// RM_IndexScanIterator is an iterator to go through index entries
class RM_IndexScanIterator {
    friend class RelationManager;

public:
    RM_IndexScanIterator() {}    // Constructor
    ~RM_IndexScanIterator() {}    // Destructor

    // "key" follows the same format as in IndexManager::insertEntry()
    RC getNextEntry(RID &rid, void *key) {
        return ix_scanIterator.getNextEntry(rid, key);
    }    // Get next matching entry
    RC close() { return ix_scanIterator.close(); }                        // Terminate index scan
private:
    IX_ScanIterator ix_scanIterator;
};

// Relation Manager
class RelationManager {
public:
    static RelationManager *instance();

    RC createCatalog();

    RC deleteCatalog();

    RC createTable(const string &tableName, const vector<Attribute> &attrs);

    RC deleteTable(const string &tableName);

    RC getAttributes(const string &tableName, vector<Attribute> &attrs);

    RC insertTuple(const string &tableName, const void *data, RID &rid);

    RC deleteTuple(const string &tableName, const RID &rid);

    RC updateTuple(const string &tableName, const void *data, const RID &rid);

    RC readTuple(const string &tableName, const RID &rid, void *data);

    // Print a tuple that is passed to this utility method.
    // The format is the same as printRecord().
    RC printTuple(const vector<Attribute> &attrs, const void *data);

    RC readAttribute(const string &tableName, const RID &rid, const string &attributeName, void *data);

    // Scan returns an iterator to allow the caller to go through the results one by one.
    // Do not store entire results in the scan iterator.
    RC scan(const string &tableName,
            const string &conditionAttribute,
            const CompOp compOp,                  // comparison type such as "<" and "="
            const void *value,                    // used in the comparison
            const vector<string> &attributeNames, // a list of projected attributes
            RM_ScanIterator &rm_ScanIterator);

    RC createIndex(const string &tableName, const string &attributeName);

    RC destroyIndex(const string &tableName, const string &attributeName);

    // indexScan returns an iterator to allow the caller to go through qualified entries in index
    RC indexScan(const string &tableName,
                 const string &attributeName,
                 const void *lowKey,
                 const void *highKey,
                 bool lowKeyInclusive,
                 bool highKeyInclusive,
                 RM_IndexScanIterator &rm_IndexScanIterator);

// Extra credit work (10 points)
public:
    RC addAttribute(const string &tableName, const Attribute &attr);

    RC dropAttribute(const string &tableName, const string &attributeName);

protected:
    RelationManager();

    ~RelationManager();

private:
    static RelationManager *_rm;
    const string TABLES_TABLE = "Tables";
    const string COLUMNS_TABLE = "Columns";
    const string INDICES_TABLE = "Indices";
    const string TABLE_ID = "table-id";
    const string TABLE_NAME = "table-name";
    const string FILE_NAME = "file-name";
    const string SYSTEM_FLAG = "system-flag";
    const string COLUMN_NAME = "column-name";
    const string COLUMN_TYPE = "column-type";
    const string COLUMN_LENGTH = "column-length";
    const string COLUMN_POSITION = "column-position";
    const string INDEX_NAME = "index-name";
    const string ATTRIBUTE_NAME = "attribute-name";
    const int TABLES_ATTR_NUM = 4;
    const int COLUMNS_ATTR_NUM = 6;
    const int INDICES_ATTR_NUM = 4;
    const int TABLES_ID = 1;
    const int COLUMNS_ID = 2;
    const int INDICES_ID = 3;

    const string CATALOG_INFO = "catalog_information";

    RecordBasedFileManager *rbfm = RecordBasedFileManager::instance();
    IndexManager *ix = IndexManager::instance();

    /** private functions called by createCatalog(...) **/
    RC insertCatalogTuple(const string &tableName, const void *data, RID &rid);

    void initializeTablesTable(); // insert essential tuples to "Tables" table as an initialization of catalog
    void initializeColumnsTable(); // insert essential tuples to "Columns" table as an initialization of catalog

    /** private functions called by createIndex(...) **/
    RC populateIndex(const string tableName, const string attributeName);

    /** private functions called by insertTuple(...) **/
    void prepareRecordDescriptorForTablesTable(vector<Attribute> &recordDescriptor);

    void prepareRecordDescriptorForColumnsTable(vector<Attribute> &recordDescriptor);

    /** private functions for reading and writing metadata **/
    RC prepareTableIdAndTablesRid(const string &tableName, int &tableId, RID &rid);

    RC prepareIndexRid(const string &indexName, RID &rid);

    RC preparePositionAttributeMap(int tableId, unordered_map<int, Attribute> &positionAttributeMap);

    RC deleteTargetTableTuplesInColumnsTable(int tableId);

    RC deleteRelatedIndicesTableTuples(const string &tableName);

    RC deleteCatalogTuple(const string &tableName, const RID &rid);

    /** private functions for general use **/
    Attribute getAttribute(const string &attributeName, int tableId);

    void updateLastTableId(uint32_t tableId);

    uint32_t getLastTableId();

    bool isSystemTable(const string &tableName);

    bool isSystemTuple(const string &tableName, const RID &rid);

    RC prepareRecordDescriptor(const string &tableName, vector<Attribute> &recordDescriptor);

    RC prepareRelatedIndices(const string &tableName, vector<Index> &relatedIndices);

    RC insertEntriesToRelatedIndices(const vector<Index> &relatedIndices, const vector<Attribute> &recordDescriptor,
                                     const void *data, const RID &rid);

    RC deleteEntriesToRelatedIndices(const vector<Index> &relatedIndices, const vector<Attribute> &recordDescriptor,
                                     const void *data, const RID &rid);

    RC deleteRelatedIndexFiles(const vector<Index> &relatedIndices);

    RC prepareKeyAndAttribute(const vector<Attribute> &recordDescriptor, const void *data, const string &attributeName,
                              void *key, Attribute &attribute);
};

// prepare tuple that would be written to "Tables" table
void prepareTupleForTables(int attributeCount, int tableID, const string &name, int isSystemInfo, void *tuple);

// prepare tuple that would be written to "Columns" table
void prepareTupleForColumns(int attributeCount, int tableID, const string &columnName, int columnType,
                            int columnLength, int columnPosition, int isSystemInfo, void *tuple);

// prepare tuple that would be written to "Tables" table
void prepareTupleForIndices(int attributeCount, const string &indexName, const string &attributeName, 
                            const string &tableName, int isSystemInfo, void *tuple);

// get the value of condition attribute for scan function
inline 
void prepareScanValue(const string &typeVarCharValue, void *value) {
    *(int *) (value) = typeVarCharValue.size();
    memcpy((char *) value + 4, typeVarCharValue.c_str(), typeVarCharValue.size());
}

inline 
void *getScanValue(int &typeIntValue) {
    return &typeIntValue;
}

inline 
void *getScanValue(float &typeRealValue) {
    return &typeRealValue;
}

#endif
