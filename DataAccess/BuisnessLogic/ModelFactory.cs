using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace DataAccess.Models
{
    abstract class ModelFactory
    {
        public abstract IProduct FactoryMethod();
    }

    class SimulationCreator : ModelFactory
    {
        public override IProduct FactoryMethod()
        {
            throw new NotImplementedException();
        }
    }
    // add more factory model implementations here
}
