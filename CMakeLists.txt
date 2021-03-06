cmake_minimum_required(VERSION 3.8)
project(cs222)

set(CMAKE_CXX_STANDARD 11)

add_library(RBF rbf/pfm.cc rbf/rbfm.cc)
add_library(IX ix/ix.cc)
target_link_libraries(IX RBF)
add_library(RM rm/rm.cc)
target_link_libraries(RM RBF IX)
add_library(QE qe/qe.cc)
target_link_libraries(QE RM)

add_executable(cs222_rbftest01 rbf/rbftest1.cc)
target_link_libraries(cs222_rbftest01 RBF)
add_executable(cs222_rbftest02 rbf/rbftest2.cc)
target_link_libraries(cs222_rbftest02 RBF)
add_executable(cs222_rbftest03 rbf/rbftest3.cc)
target_link_libraries(cs222_rbftest03 RBF)
add_executable(cs222_rbftest04 rbf/rbftest4.cc)
target_link_libraries(cs222_rbftest04 RBF)
add_executable(cs222_rbftest05 rbf/rbftest5.cc)
target_link_libraries(cs222_rbftest05 RBF)
add_executable(cs222_rbftest06 rbf/rbftest6.cc)
target_link_libraries(cs222_rbftest06 RBF)
add_executable(cs222_rbftest07 rbf/rbftest7.cc)
target_link_libraries(cs222_rbftest07 RBF)
add_executable(cs222_rbftest08 rbf/rbftest8.cc)
target_link_libraries(cs222_rbftest08 RBF)
add_executable(cs222_rbftest08b rbf/rbftest8b.cc)
target_link_libraries(cs222_rbftest08b RBF)
add_executable(cs222_rbftest09 rbf/rbftest9.cc)
target_link_libraries(cs222_rbftest09 RBF)
add_executable(cs222_rbftest10 rbf/rbftest10.cc)
target_link_libraries(cs222_rbftest10 RBF)
add_executable(cs222_rbftest11 rbf/rbftest11.cc)
target_link_libraries(cs222_rbftest11 RBF)
add_executable(cs222_rbftest12 rbf/rbftest12.cc)
target_link_libraries(cs222_rbftest12 RBF)
add_executable(cs222_rbftest_delete rbf/rbftest_delete.cc)
target_link_libraries(cs222_rbftest_delete RBF)
add_executable(cs222_rbftest_update rbf/rbftest_update.cc)
target_link_libraries(cs222_rbftest_update RBF)
add_executable(cs222_rbftest_p0 rbf/rbftest_p0.cc)
target_link_libraries(cs222_rbftest_p0 RBF)
add_executable(cs222_rbftest_p1 rbf/rbftest_p1.cc)
target_link_libraries(cs222_rbftest_p1 RBF)
add_executable(cs222_rbftest_p1b rbf/rbftest_p1b.cc)
target_link_libraries(cs222_rbftest_p1b RBF)
add_executable(cs222_rbftest_p1c rbf/rbftest_p1c.cc)
target_link_libraries(cs222_rbftest_p1c RBF)
add_executable(cs222_rbftest_p2 rbf/rbftest_p2.cc)
target_link_libraries(cs222_rbftest_p2 RBF)
add_executable(cs222_rbftest_p2b rbf/rbftest_p2b.cc)
target_link_libraries(cs222_rbftest_p2b RBF)
add_executable(cs222_rbftest_p3 rbf/rbftest_p3.cc)
target_link_libraries(cs222_rbftest_p3 RBF)
add_executable(cs222_rbftest_p4 rbf/rbftest_p4.cc)
target_link_libraries(cs222_rbftest_p4 RBF)
add_executable(cs222_rbftest_p5 rbf/rbftest_p5.cc)
target_link_libraries(cs222_rbftest_p5 RBF)

add_executable(cs222_rmtest_00 rm/rmtest_00.cc)
target_link_libraries(cs222_rmtest_00 RM)
add_executable(cs222_rmtest_01 rm/rmtest_01.cc)
target_link_libraries(cs222_rmtest_01 RM)
add_executable(cs222_rmtest_02 rm/rmtest_02.cc)
target_link_libraries(cs222_rmtest_02 RM)
add_executable(cs222_rmtest_03 rm/rmtest_03.cc)
target_link_libraries(cs222_rmtest_03 RM)
add_executable(cs222_rmtest_04 rm/rmtest_04.cc)
target_link_libraries(cs222_rmtest_04 RM)
add_executable(cs222_rmtest_05 rm/rmtest_05.cc)
target_link_libraries(cs222_rmtest_05 RM)
add_executable(cs222_rmtest_06 rm/rmtest_06.cc)
target_link_libraries(cs222_rmtest_06 RM)
add_executable(cs222_rmtest_07 rm/rmtest_07.cc)
target_link_libraries(cs222_rmtest_07 RM)
add_executable(cs222_rmtest_08 rm/rmtest_08.cc)
target_link_libraries(cs222_rmtest_08 RM)
add_executable(cs222_rmtest_09 rm/rmtest_09.cc)
target_link_libraries(cs222_rmtest_09 RM)
add_executable(cs222_rmtest_10 rm/rmtest_10.cc)
target_link_libraries(cs222_rmtest_10 RM)
add_executable(cs222_rmtest_11 rm/rmtest_11.cc)
target_link_libraries(cs222_rmtest_11 RM)
add_executable(cs222_rmtest_12 rm/rmtest_12.cc)
target_link_libraries(cs222_rmtest_12 RM)
add_executable(cs222_rmtest_13 rm/rmtest_13.cc)
target_link_libraries(cs222_rmtest_13 RM)
add_executable(cs222_rmtest_13b rm/rmtest_13b.cc)
target_link_libraries(cs222_rmtest_13b RM)
add_executable(cs222_rmtest_14 rm/rmtest_14.cc)
target_link_libraries(cs222_rmtest_14 RM)
add_executable(cs222_rmtest_15 rm/rmtest_15.cc)
target_link_libraries(cs222_rmtest_15 RM)
add_executable(cs222_rmtest_create_tables rm/rmtest_create_tables.cc)
target_link_libraries(cs222_rmtest_create_tables RM)
add_executable(cs222_rmtest_delete_tables rm/rmtest_delete_tables.cc)
target_link_libraries(cs222_rmtest_delete_tables RM)
add_executable(cs222_rmtest_extra_1 rm/rmtest_extra_1.cc)
target_link_libraries(cs222_rmtest_extra_1 RM)
add_executable(cs222_rmtest_extra_2 rm/rmtest_extra_2.cc)
target_link_libraries(cs222_rmtest_extra_2 RM)
add_executable(cs222_rmtest_p0 rm/rmtest_p0.cc)
target_link_libraries(cs222_rmtest_p0 RM)
add_executable(cs222_rmtest_p1 rm/rmtest_p1.cc)
target_link_libraries(cs222_rmtest_p1 RM)
add_executable(cs222_rmtest_p2 rm/rmtest_p2.cc)
target_link_libraries(cs222_rmtest_p2 RM)
add_executable(cs222_rmtest_p3 rm/rmtest_p3.cc)
target_link_libraries(cs222_rmtest_p3 RM)
add_executable(cs222_rmtest_p4 rm/rmtest_p4.cc)
target_link_libraries(cs222_rmtest_p4 RM)
add_executable(cs222_rmtest_p5 rm/rmtest_p5.cc)
target_link_libraries(cs222_rmtest_p5 RM)
add_executable(cs222_rmtest_p6 rm/rmtest_p6.cc)
target_link_libraries(cs222_rmtest_p6 RM)
add_executable(cs222_rmtest_p7 rm/rmtest_p7.cc)
target_link_libraries(cs222_rmtest_p7 RM)
add_executable(cs222_rmtest_p8 rm/rmtest_p8.cc)
target_link_libraries(cs222_rmtest_p8 RM)
add_executable(cs222_rmtest_p9 rm/rmtest_p9.cc)
target_link_libraries(cs222_rmtest_p9 RM)

add_executable(cs222_ixtest_01 ix/ixtest_01.cc)
target_link_libraries(cs222_ixtest_01 IX)
add_executable(cs222_ixtest_02 ix/ixtest_02.cc)
target_link_libraries(cs222_ixtest_02 IX)
add_executable(cs222_ixtest_03 ix/ixtest_03.cc)
target_link_libraries(cs222_ixtest_03 IX)
add_executable(cs222_ixtest_04 ix/ixtest_04.cc)
target_link_libraries(cs222_ixtest_04 IX)
add_executable(cs222_ixtest_05 ix/ixtest_05.cc)
target_link_libraries(cs222_ixtest_05 IX)
add_executable(cs222_ixtest_06 ix/ixtest_06.cc)
target_link_libraries(cs222_ixtest_06 IX)
add_executable(cs222_ixtest_07 ix/ixtest_07.cc)
target_link_libraries(cs222_ixtest_07 IX)
add_executable(cs222_ixtest_08 ix/ixtest_08.cc)
target_link_libraries(cs222_ixtest_08 IX)
add_executable(cs222_ixtest_09 ix/ixtest_09.cc)
target_link_libraries(cs222_ixtest_09 IX)
add_executable(cs222_ixtest_10 ix/ixtest_10.cc)
target_link_libraries(cs222_ixtest_10 IX)
add_executable(cs222_ixtest_11 ix/ixtest_11.cc)
target_link_libraries(cs222_ixtest_11 IX)
add_executable(cs222_ixtest_12 ix/ixtest_12.cc)
target_link_libraries(cs222_ixtest_12 IX)
add_executable(cs222_ixtest_13 ix/ixtest_13.cc)
target_link_libraries(cs222_ixtest_13 IX)
add_executable(cs222_ixtest_14 ix/ixtest_14.cc)
target_link_libraries(cs222_ixtest_14 IX)
add_executable(cs222_ixtest_15 ix/ixtest_15.cc)
target_link_libraries(cs222_ixtest_15 IX)
add_executable(cs222_ixtest_extra_01 ix/ixtest_extra_01.cc)
target_link_libraries(cs222_ixtest_extra_01 IX)
add_executable(cs222_ixtest_extra_02 ix/ixtest_extra_02.cc)
target_link_libraries(cs222_ixtest_extra_02 IX)
add_executable(cs222_ixtest_p1 ix/ixtest_p1.cc)
target_link_libraries(cs222_ixtest_p1 IX)
add_executable(cs222_ixtest_p2 ix/ixtest_p2.cc)
target_link_libraries(cs222_ixtest_p2 IX)
add_executable(cs222_ixtest_p3 ix/ixtest_p3.cc)
target_link_libraries(cs222_ixtest_p3 IX)
add_executable(cs222_ixtest_p4 ix/ixtest_p4.cc)
target_link_libraries(cs222_ixtest_p4 IX)
add_executable(cs222_ixtest_p5 ix/ixtest_p5.cc)
target_link_libraries(cs222_ixtest_p5 IX)
add_executable(cs222_ixtest_p6 ix/ixtest_p6.cc)
target_link_libraries(cs222_ixtest_p6 IX)
add_executable(cs222_ixtest_pe_01 ix/ixtest_pe_01.cc)
target_link_libraries(cs222_ixtest_pe_01 IX)
add_executable(cs222_ixtest_pe_02 ix/ixtest_pe_02.cc)
target_link_libraries(cs222_ixtest_pe_02 IX)

add_executable(cs222_qetest_01 qe/qetest_01.cc)
target_link_libraries(cs222_qetest_01 QE)
add_executable(cs222_qetest_02 qe/qetest_02.cc)
target_link_libraries(cs222_qetest_02 QE)
add_executable(cs222_qetest_03 qe/qetest_03.cc)
target_link_libraries(cs222_qetest_03 QE)
add_executable(cs222_qetest_04 qe/qetest_04.cc)
target_link_libraries(cs222_qetest_04 QE)
add_executable(cs222_qetest_05 qe/qetest_05.cc)
target_link_libraries(cs222_qetest_05 QE)
add_executable(cs222_qetest_06 qe/qetest_06.cc)
target_link_libraries(cs222_qetest_06 QE)
add_executable(cs222_qetest_07 qe/qetest_07.cc)
target_link_libraries(cs222_qetest_07 QE)
add_executable(cs222_qetest_08 qe/qetest_08.cc)
target_link_libraries(cs222_qetest_08 QE)
add_executable(cs222_qetest_09 qe/qetest_09.cc)
target_link_libraries(cs222_qetest_09 QE)
add_executable(cs222_qetest_10 qe/qetest_10.cc)
target_link_libraries(cs222_qetest_10 QE)
add_executable(cs222_qetest_11 qe/qetest_11.cc)
target_link_libraries(cs222_qetest_11 QE)
add_executable(cs222_qetest_12 qe/qetest_12.cc)
target_link_libraries(cs222_qetest_12 QE)
add_executable(cs222_qetest_13 qe/qetest_13.cc)
target_link_libraries(cs222_qetest_13 QE)
add_executable(cs222_qetest_14 qe/qetest_14.cc)
target_link_libraries(cs222_qetest_14 QE)
add_executable(cs222_qetest_15 qe/qetest_15.cc)
target_link_libraries(cs222_qetest_15 QE)
add_executable(cs222_qetest_16 qe/qetest_16.cc)
target_link_libraries(cs222_qetest_16 QE)
add_executable(cs222_qetest_p00 qe/qetest_p00.cc)
target_link_libraries(cs222_qetest_p00 QE)
add_executable(cs222_qetest_p01 qe/qetest_p01.cc)
target_link_libraries(cs222_qetest_p01 QE)
add_executable(cs222_qetest_p02 qe/qetest_p02.cc)
target_link_libraries(cs222_qetest_p02 QE)
add_executable(cs222_qetest_p03 qe/qetest_p03.cc)
target_link_libraries(cs222_qetest_p03 QE)
add_executable(cs222_qetest_p04 qe/qetest_p04.cc)
target_link_libraries(cs222_qetest_p04 QE)
add_executable(cs222_qetest_p05 qe/qetest_p05.cc)
target_link_libraries(cs222_qetest_p05 QE)
add_executable(cs222_qetest_p06 qe/qetest_p06.cc)
target_link_libraries(cs222_qetest_p06 QE)
add_executable(cs222_qetest_p07 qe/qetest_p07.cc)
target_link_libraries(cs222_qetest_p07 QE)
add_executable(cs222_qetest_p08 qe/qetest_p08.cc)
target_link_libraries(cs222_qetest_p08 QE)
add_executable(cs222_qetest_p09 qe/qetest_p09.cc)
target_link_libraries(cs222_qetest_p09 QE)
add_executable(cs222_qetest_p10 qe/qetest_p10.cc)
target_link_libraries(cs222_qetest_p10 QE)
add_executable(cs222_qetest_p11 qe/qetest_p11.cc)
target_link_libraries(cs222_qetest_p11 QE)
add_executable(cs222_qetest_p12 qe/qetest_p12.cc)
target_link_libraries(cs222_qetest_p12 QE)
