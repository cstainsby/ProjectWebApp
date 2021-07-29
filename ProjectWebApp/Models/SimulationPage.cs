using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace ProjectWebApp.Models
{
    public class SimulationPage
    {
        public int Id { get; set; }

        // defines what the project type will be 
        public string ProjectType { get; set; }

        // path string to the C++ program that will be run
        public string SimCnn { get; set; }




    }
}
