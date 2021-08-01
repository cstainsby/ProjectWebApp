


using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DataAccess.Models
{
    public class SimulationModel : Model
    {
        public override int Id { get; set; }
        public string simName { get; set; }
        public string simDesc { get; set; }
        public string gitURL { get; set; }

        public SimulationModel()
        {

        }
    }
}
