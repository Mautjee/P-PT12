using System;
using System.Data;
using System.Data.SqlClient;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Drawing;

namespace HarmonieApp
{
    class Database
    {

        public DataType GetQueryValue(valueType ValueType, string[] _query, string[] parameters, string[] parameterNames)
        {
            try
            {
                using (SqlConnection connection = new SqlConnection(GetConnection().ConnectionString))
                {
                    connection.Open();
                    return ExecuteQuery(ValueType, parameters, parameterNames, _query, connection);
                }
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.ToString());
                return null;
            }
        }
        //TODO: when you got 2 querrys with 2 different parameters, You need to seperate them!!!
        public void InsertQuery(string _query, string[] parameters, string[] parameterNames)
        {
            try
            {
                using(SqlConnection connection = new SqlConnection(GetConnection().ConnectionString))
                {
                    connection.Open();
                    using (SqlCommand command = new SqlCommand(_query, connection))
                    {
                        command.CommandText = _query;
                        command.ExecuteNonQuery();
                    }
                }
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.ToString());
            }
        }

        #region PrivateMethods
        private SqlConnectionStringBuilder GetConnection()
        {
            try
            {
                SqlConnectionStringBuilder builder = new SqlConnectionStringBuilder();
                builder.DataSource = "salty.database.windows.net";
                builder.UserID = "kahing.wong@student.fontys.nl";
                builder.Password = "Snsd11586!";
                builder.InitialCatalog = "PT-12Database";

                return builder;
            }
            catch
            {
                return null;
            }
        }
        private DataType ExecuteQuery(valueType ValueType, string[] parameters, string[] parameterNames, String[] sqlArray, SqlConnection connection)
        {
            foreach (string sql in sqlArray)
            {
                using (SqlCommand command = new SqlCommand(sql, connection))
                {
                    if(parameters.Length != 0 || parameterNames.Length != 0)
                    {
                        GetParameters(parameters, parameterNames, command);
                    }
                    SqlDataReader reader = command.ExecuteReader();
                    if (reader.HasRows)
                    {                        
                        if (ValueType.Equals(valueType.dataTable))
                        {
                            DataTable datatable = new DataTable();
                            datatable.Load(reader);
                            return new DataType(datatable);
                        }
                        else if (ValueType.Equals(valueType.seedCoordinatesList))
                        {
                            return SetCoordinates(reader);
                        }
                        else if (ValueType.Equals(valueType.String))
                        {
                            return SetString(reader);
                        }
                        else if (ValueType.Equals(valueType.wordList))
                        {
                            return SetWordList(reader);
                        }
                    }
                    else
                    {
                        reader.Close();
                    }
                }
            }
            return null;
        }
        private void GetParameters(string[] parameters, string[] parameterNames, SqlCommand command)
        {
            if(command.Parameters.Count != 0)
            {
                command.Parameters.Clear();
            }
            if (parameters.Length == parameterNames.Length)
            {
                for (int i = 0; i < parameters.Length; i++)
                {
                    command.Parameters.Add(parameterNames[i], SqlDbType.NVarChar);
                    command.Parameters[parameterNames[i]].Value = parameters[i];
                }
            }
        }
        #region dataTypeMethods
        private DataType SetCoordinates(SqlDataReader reader)
        {
            using (reader)
            {
                List<Point> seedcoordsList = new List<SeedCoordinates>();
                while (reader.Read())
                {
                    SeedCoordinates seedCoordinates = new SeedCoordinates(reader.GetInt32(0), reader.GetInt32(1));
                    seedcoordsList.Add(seedCoordinates);
                }
                return new DataType(seedcoordsList);
            }
        }
        private DataType SetString(SqlDataReader reader)
        {
            using (reader)
            {
                while (reader.Read())
                {
                    return new DataType(reader.GetValue(0).ToString());
                }
                return null;
            }
        }
        private DataType SetWordList(SqlDataReader reader)
        {
            using (reader)
            {
                List<string> wordList = new List<string>();
                while (reader.Read())
                {
                    wordList.Add(reader.GetString(0) + " " + reader.GetString(1));
                }
                return new DataType(wordList);
            }
        }
        #endregion
        private void GetResultSeedCoordinates(SqlDataReader reader, string[] MemberIDs)
        {
            //return a list of x,y coordinates from your querry result (Instruments and Persons)
            using (reader)
            {
                while (reader.Read())
                {
                    string[] Parameters = { reader.GetValue(reader.GetOrdinal("MemberID")).ToString() };
                    string[] ParameterNames = { "@memberID" };
                    string[] Querry = { "SELECT XCoord, YCoord FROM Seeds WHERE MemberID = @memberID; " };
                    ResultCoordinates.AddRange(GetQueryValue(valueType.seedCoordinatesList, Querry, Parameters, ParameterNames).seedCoordsList);
                }
            }
        }
        #endregion

        public enum valueType
        {
            dataTable,
            seedCoordinatesList,
            String,
            wordList,
        }
    }
}
