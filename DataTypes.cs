using System;
using System.Data;
using System.Data.SqlClient;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace HarmonieApp
{
    class DataType
    {

        private DataTable datatable = new DataTable();
        private List<Point> seedcoordsList = new List<Point>();
        private string Value;
        private List<string> wordlist = new List<string>();

        public DataTable dataTable { get { return datatable; } }
        public List<Point> seedCoordsList { get { return seedcoordsList; } }
        public string value { get { return Value; } }
        public List<string> wordList { get { return wordlist; } }

        public DataType (DataTable dataTable)
        {
            datatable = dataTable;
        }
        public DataType (List<Point> seedCoordsList)
        {
            seedcoordsList = seedCoordsList;
        }
        public DataType (string value)
        {
            Value = value;
        }
        public DataType(List<string> wordList)
        {
            wordlist = wordList;
        }
    }
}
