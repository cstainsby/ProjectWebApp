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
        public async Task GetSimulationAsync_ValidCall()
        {
            // Arrange
            // create a new simulation
            var simulation = new SimulationModel()
            {
                Id = 1,
                simName = "name",
                gitURL = "test", 
                simDesc = "test2"
            };
            int collect_Id = 1;
            var sim_repo = new Mock<ISimulationRepository>();                            // mock the Simulation repository
            sim_repo.Setup(x => x.GetByIdAsync(simulation.Id)).ReturnsAsync(simulation); // if the GetByIdAsync(Id) is called, should return simulation

            // Act 
            SimulationController sim_controller = new SimulationController();
            var result = await sim_controller.

            // Assert
            Assert.Equal();
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
