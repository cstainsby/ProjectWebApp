using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Autofac.Extras.Moq;
using Xunit;
using DataAccess.Models;
using DataAccess.Repositories;

/*
 * To test the repositories functionality and their generic functions i.e  add, remove, etc 
 */

namespace ProjectUnitTests.Repositories
{
    public class RepositoryTest
    {
        [Theory]
        public void CreateSimulationTest(string simName, string simDesc, string gitURL)
        {
            // the item inside the using will be automatically disposed of when brackets end
            using (var mock = AutoMock.GetLoose())
            {
                mock.Mock<>(); 
            }
        }

        public void CreateSimulation_ThrowsException()
        {

        }

        private List<SimulationModel> GetSampleSimulations()
        {
            List<SimulationModel> models = new List<SimulationModel>
            {
                new SimulationModel
                {
                    Id = 1,
                    simName = "Fluid Sim",
                    gitURL = "https://github.com/cstainsby/FluidSimulator",

                },

            };
        }
    }
}
