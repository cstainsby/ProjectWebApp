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
        public async void SimulationGetAllAsync_RepositoryTest()
        {
            // Arrange
            IEnumerable<SimulationModel> simulations = GetSampleSimulations();

            // mock the Simulation repository
            var mock_sim_repo = new Mock<ISimulationRepository>();
            
            // return all of the simulations 
            mock_sim_repo.Setup(x => x.GetAllAsync()).ReturnsAsync(simulations).Verifiable();

            // mock unit of work 
            var unitOfWorkMock = new Mock<IUnitOfWork>();

            // when unit of work builds a simulation repo, check that it outputs correctly
            unitOfWorkMock.Setup(x => x.SimulationRepo).Returns(mock_sim_repo.Object);


            var sim_repo = mock_sim_repo.Object;
            var unit_sim_repo = unitOfWorkMock.Object.SimulationRepo; // get a simulation repo from the mocked unitOfWork

            // Act
            // find all simulations from mocked unitOfWork
            var actual = await unit_sim_repo.GetAllAsync();

            // find all simulations from mocked Simulation repo
            IEnumerable<SimulationModel> test_sims = await sim_repo.GetAllAsync();

            // Assert
            // neither the test or the actual results should be null
            Assert.True(test_sims != null);
            Assert.True(actual != null);

            // make sure in both that all of the simulations are accounted for
            Assert.Equal(2, test_sims.ToList().Count);
            Assert.Equal(2, actual.ToList().Count);

            // Compare the lists to make sure that they are equal
            Assert.Equal(test_sims.ToList(), actual.ToList());
        }

        [Fact]
        public async void SimulationGetById_RepositoryTest()
        {
            // Arrange
            IEnumerable<SimulationModel> simulations = GetSampleSimulations();

            // mock the Simulation repository
            var mock_sim_repo = new Mock<ISimulationRepository>();

            // By accessing any index within the list of simulations, it the repo should return the  
            // sim with the corresponding index
            int any_index = It.IsAny<int>();
            mock_sim_repo.Setup(x => x.GetByIdAsync(any_index)).ReturnsAsync(simulations.ToList()[any_index]).Verifiable();

            // mock unit of work 
            var unitOfWorkMock = new Mock<IUnitOfWork>();

            // when unit of work builds a simulation repo, check that it outputs correctly
            unitOfWorkMock.Setup(x => x.SimulationRepo).Returns(mock_sim_repo.Object);


            var sim_repo = mock_sim_repo.Object;
            var unit_sim_repo = unitOfWorkMock.Object.SimulationRepo; // get a simulation repo from the mocked unitOfWork

            // Act
            // find sim from mocked unitOfWork at any index
            var actual = await unit_sim_repo.GetByIdAsync(any_index);

            // find product from sim_repo at the same index
            SimulationModel test_sims = await sim_repo.GetByIdAsync(any_index);

            // Assert
            // neither the test or the actual results should be null
            Assert.True(test_sims != null);
            Assert.True(actual != null);

            // Compare all elements to ensure no data was lost/altered
            Assert.Equal(test_sims.Id, actual.Id);
            Assert.Equal(test_sims.simName, actual.simName);
            Assert.Equal(test_sims.simDesc, actual.simDesc);
            Assert.Equal(test_sims.gitURL, actual.gitURL);
        }


        // helper function to generate sample simulations to work with 
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
