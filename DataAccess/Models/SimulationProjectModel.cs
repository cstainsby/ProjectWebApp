


using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DataAccess.Models
{
    public class SimulationProjectModel : AbstractProjectModel
    {
        public override int Id { get; set; }
        public override string projectType { get; set; }
        public override string simName { get; set; }
        public override string simDesc { get; set; }
        public override string gitURL { get; set; }

        public bool placeableMenu { get; set; } // should there be a menu for user interaction options
        public List<string> placeableFuncs { get; set; } // list of functions that can be used by user in simulation

        public SimulationProjectModel()
        {

        }
    }
}
