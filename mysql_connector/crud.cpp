/* Copyright 2008, 2010, Oracle and/or its affiliates. All rights reserved.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

There are special exceptions to the terms and conditions of the GPL
as it is applied to this software. View the full text of the
exception in file EXCEPTIONS-CONNECTOR-C++ in the directory of this
software distribution.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

#include <vector>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h> //sql::PreparedStatement

//using namespace std;

//https://archive.md/TeGBj#selection-2819.1-2847.1
//g++ crud.cpp -I/usr/include/mysql-cppconn-8/jdbc -I/usr/include/mysql-cppconn-8/mysqlx -lmysqlcppconn -std=c++11

void insert(sql::Statement *stmt, std::string phone, time_t timestamp, std::vector<float> embedding){
/*
    //https://stackoverflow.com/questions/13558369/inserting-a-variable-into-a-mysql-table
    query = "INSERT INTO mytable VALUES (?, ?, ?, ?)";
    pstmt = con->prepareStatement(query);
    pstmt->setString(1, phone);
    pstmt->setString(2, timestamp); 
    pstmt->setDouble(3, embedding[0]);
    pstmt->execute();
*/
    std::string query;
    query = "INSERT INTO mytable VALUES (";
    query += phone; query += ", ";
    //query += "'1965-10-31 01:00:00'"; query += ", ";
    //https://stackoverflow.com/questions/2067433/convert-mysql-timestamp-to-time-t
    //https://dev.mysql.com/doc/refman/5.5/en/date-and-time-functions.html#function_from-unixtime
    query += "FROM_UNIXTIME("; query += std::to_string(timestamp); query += ")"; query += ", ";
    for(int i = 0; i < embedding.size(); i++){
        query += std::to_string(embedding[i]);
        if(i != embedding.size() - 1){
           query += ", ";
        }
    }
    query += ")";
    std::cout << query << std::endl;

    //https://stackoverflow.com/questions/6903383/mysql-query-executes-but-throws-exception
    //https://stackoverflow.com/questions/48834461/error-message-after-inserting-to-a-table-in-mysql-db?noredirect=1&lq=1
    //res = stmt->executeQuery(query);
    stmt->execute(query);
    std::cout << "insert finish" << std::endl;
}

void update(sql::Statement *stmt, std::string phone){
    std::string query;
    query = "UPDATE mytable SET phone="; query += phone; query+=" ";
    query += "WHERE phone=12345678901"; query += "";
    std::cout << query << std::endl;
    stmt->execute(query);
    std::cout << "update finish" << std::endl;
}

std::string select(sql::Statement *stmt, sql::ResultSet *res){
    std::string query, res_str;
    query = "SELECT * FROM mytable";
    res = stmt->executeQuery(query);
    std::cout << "select finish" << std::endl;
    while (res->next()) {
        res_str += res->getString(1); res_str += " ";
        res_str += res->getString(2); res_str += " ";
        for(int i = 3; i < 3 + 128; i++){
            //https://stackoverflow.com/questions/15412542/mysql-connector-c-and-floats
            res_str += std::to_string(res->getDouble(i)); res_str += " ";
        }
        res_str += "\n";
    }
    return res_str;
}

std::string get_count(sql::Statement *stmt, sql::ResultSet *res){
    std::string query, res_str;
    query = "SELECT COUNT(*) FROM mytable";
    res = stmt->executeQuery(query);
    while (res->next()) {
        res_str += std::to_string(res->getInt(1));
    }
    return res_str;
}

int main(void)
{
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;
        sql::PreparedStatement *pstmt;
        std::string query;
 
        std::string phone = "12345678901";
        time_t timestamp = time(0);
        std::vector<float> embedding(128);
        std::string res_str;

        for(int i = 0; i < embedding.size(); i++){
            embedding[i] = 3.0f;
        }

        /* Create a connection */
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
        /* Connect to the MySQL test database */
        con->setSchema("mydb");
    
        stmt = con->createStatement();
        insert(stmt, phone, timestamp, embedding);

        res_str = select(stmt, res);
        std::cout << res_str << std::endl;

        update(stmt, "09876543210");

        res_str = select(stmt, res);
        std::cout << res_str << std::endl;

        res_str = get_count(stmt, res);
        std::cout << res_str << std::endl;

        delete res;
        delete stmt;
        delete con;
    
    } catch (sql::SQLException &e) {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
    
    return EXIT_SUCCESS;
}
