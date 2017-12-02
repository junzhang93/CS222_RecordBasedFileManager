#ifndef CS222_UTIL_H
#define CS222_UTIL_H

#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sys/stat.h>

using namespace std;

// Calculate actual bytes for nulls-indicator for the given field counts
int getByteOfNullsIndicator(int fieldCount) {
    return ceil((double) fieldCount / CHAR_BIT);
}

// prepare tuple that would be written to "Tables" table
void prepareTupleForTables(int attributeCount, const int tableID, const string &name,
                           const int isSystemInfo, void *tuple) {
    int offset = 0;
    int nullAttributesIndicatorActualSize = getByteOfNullsIndicator(attributeCount);
    int nameLength = name.size();

    // write Null-indicator to tuple record
    memset((char *) tuple + offset, 0, nullAttributesIndicatorActualSize);
    offset += nullAttributesIndicatorActualSize;

    // write tableID to tuple record
    memcpy((char *) tuple + offset, &tableID, sizeof(int));
    offset += sizeof(int);

    // write tableName to tuple record
    memcpy((char *) tuple + offset, &nameLength, sizeof(uint32_t));
    offset += sizeof(int);
    memcpy((char *) tuple + offset, name.c_str(), nameLength);
    offset += nameLength;

    // write fileName to tuple record
    memcpy((char *) tuple + offset, &nameLength, sizeof(uint32_t));
    offset += sizeof(int);
    memcpy((char *) tuple + offset, name.c_str(), nameLength);
    offset += nameLength;

    // write isSystemInfo to tuple record
    memcpy((char *) tuple + offset, &isSystemInfo, sizeof(int));
    offset += sizeof(int);
}

// prepare tuple that would be written to "Columns" table
void prepareTupleForColumns(int attributeCount, const int tableID, const string &columnName, const int columnType,
                            const int columnLength, const int columnPosition, const int isSystemInfo, void *tuple) {
    int offset = 0;
    int nullAttributesIndicatorActualSize = getByteOfNullsIndicator(attributeCount);
    int nameLength = columnName.size();

    // write Null-indicator to tuple record
    memset((char *) tuple + offset, 0, nullAttributesIndicatorActualSize);
    offset += nullAttributesIndicatorActualSize;

    // write tableID to tuple record
    memcpy((char *) tuple + offset, &tableID, sizeof(int));
    offset += sizeof(int);

    // write columnName to tuple record
    memcpy((char *) tuple + offset, &nameLength, sizeof(uint32_t));
    offset += sizeof(int);
    memcpy((char *) tuple + offset, columnName.c_str(), nameLength);
    offset += nameLength;

    // write columnType to tuple record
    memcpy((char *) tuple + offset, &columnType, sizeof(int));
    offset += sizeof(int);

    // write columnLength to tuple record
    memcpy((char *) tuple + offset, &columnLength, sizeof(int));
    offset += sizeof(int);

    // write columnPosition to tuple record
    memcpy((char *) tuple + offset, &columnPosition, sizeof(int));
    offset += sizeof(int);

    // write isSystemInfo to tuple record
    memcpy((char *) tuple + offset, &isSystemInfo, sizeof(int));
    offset += sizeof(int);
}

// prepare tuple that would be written to "Tables" table
void
prepareTupleForIndices(int attributeCount, const string indexName, const string attributeName, const string tableName,
                       const int isSystemInfo, void *tuple) {
    int offset = 0;
    int nullAttributesIndicatorActualSize = getByteOfNullsIndicator(attributeCount);
    int nameLength = indexName.size();

    // write Null-indicator to tuple record
    memset((char *) tuple + offset, 0, nullAttributesIndicatorActualSize);
    offset += nullAttributesIndicatorActualSize;

    // write indexName to tuple record
    memcpy((char *) tuple + offset, &nameLength, sizeof(uint32_t));
    offset += sizeof(int);
    memcpy((char *) tuple + offset, indexName.c_str(), nameLength);
    offset += nameLength;

    // write attributeName to tuple record
    nameLength = attributeName.size();
    memcpy((char *) tuple + offset, &nameLength, sizeof(uint32_t));
    offset += sizeof(int);
    memcpy((char *) tuple + offset, attributeName.c_str(), nameLength);
    offset += nameLength;

    // write tableName to tuple record
    nameLength = tableName.size();
    memcpy((char *) tuple + offset, &nameLength, sizeof(uint32_t));
    offset += sizeof(int);
    memcpy((char *) tuple + offset, tableName.c_str(), nameLength);
    offset += nameLength;

    // write isSystemInfo to tuple record
    memcpy((char *) tuple + offset, &isSystemInfo, sizeof(int));
    offset += sizeof(int);
}

// get the value of condition attribute for scan function
void prepareScanValue(const string typeVarCharValue, void *value) {
    *(int *) (value) = typeVarCharValue.size();
    memcpy((char *) value + 4, typeVarCharValue.c_str(), typeVarCharValue.size());
}

void *getScanValue(int &typeIntValue) {
    return &typeIntValue;
}

void *getScanValue(float &typeRealValue) {
    return &typeRealValue;
}

#endif //CS222_UTIL_H
