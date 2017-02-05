cmake_minimum_required(VERSION 3.6)
project(AnalystComparer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Utils.cpp Utils.h Comparer.cpp Comparer.h Constants.h Analyst.cpp Analyst.hpp History.cpp History.hpp PurchaseSale.cpp PurchaseSale.hpp FormattedTable.cpp FormattedTable.hpp FormattedRow.cpp FormattedRow.hpp FormattedCell.cpp FormattedCell.hpp ColumnDefinition.cpp ColumnDefinition.hpp)
add_executable(AnalystComparer ${SOURCE_FILES} FormattedTable.cpp FormattedTable.hpp FormattedRow.cpp FormattedRow.hpp FormattedCell.cpp FormattedCell.hpp)