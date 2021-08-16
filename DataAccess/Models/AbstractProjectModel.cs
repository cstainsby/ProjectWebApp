using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DataAccess.Models
{
    public abstract class AbstractProjectModel
    {
        public abstract int Id { get; set; }
        public abstract string simName { get; set; }
        public abstract string simDesc { get; set; }
        public abstract string gitURL { get; set; }
    }
}
