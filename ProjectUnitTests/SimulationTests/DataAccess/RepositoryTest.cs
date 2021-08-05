using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Autofac.Extras.Moq;
using Moq;
using Xunit;
using DataAccess.Models;
using DataAccess.Repositories;
using ProjectWebApp.Controllers;

/*
 * To test the repositories functionality and their generic functions i.e  add, remove, etc 
 */

namespace ProjectUnitTests.Repositories
{
    public class RepositoryTest
    {
        [Fact]
        public async void GetIdByAsync_ValidCall()
        {
            using(var mock = AutoMock.GetLoose())
            {
                // mock a UnitOfWork class and use it to get a simulation repository which returns "GetAllAsync"
                // compare the return value to GetSampleSimulation()'s return
                mock.Mock<IUnitOfWork>()
                    .Setup(x => x.SimulationRepo.GetAllAsync())
                    .ReturnsAsync(GetSampleSimulations());

                var cls = mock.Create<Repository>;
                var expected = GetSampleSimulations();

                var actual = await cls.
            }
        }

        private IEnumerable<SimulationModel> GetSampleSimulations()
        {
            List<SimulationModel> models = new List<SimulationModel>
            {
                new SimulationModel
                {
                    simName = "Fluid Sim",
                    gitURL = "https://github.com/cstainsby/FluidSimulator",
                    simDesc = "words w0rds"
                },

                new SimulationModel
                {
                    simName = "Color Sim",
                    gitURL = "https://github.com/cstainsby",
                    simDesc = "words w0rds more words"
                }
            };
            // return the list as an IEnumerable 
            return models;
        }
    }
}
