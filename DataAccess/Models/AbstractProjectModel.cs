using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DataAccess.Models
{
    public abstract class AbstractProjectModel
    {
        public abstract int Id { get; set; } // Id
        public abstract string projectType { get; set; } // string containing accepted project types
        public abstract string simName { get; set; } // name of project
        public abstract string simDesc { get; set; } // description of sim
        public abstract string gitURL { get; set; } // URL to github with the src code
    }
}
