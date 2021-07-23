using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations;

namespace ProjectWebApp.Models
{
    public class Simulation
    {
        [Display(Name="Simulation Id")]
        public int Id { get; set; }

        [Display(Name="Simulation Name")]
        public string simName { get; set; }

        [Display(Name="Simulation Description")]
        public string simDesc { get; set; }

        [Display(Name="GitHub URL")]
        [DataType(DataType.Url)]
        public string gitUrl { get; set; }
    }
}
