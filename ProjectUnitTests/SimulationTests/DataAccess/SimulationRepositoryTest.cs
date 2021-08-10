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
    public class SimulationRepositoryTest
    {
        [Fact]
        public void SimulationGetAllAsync_RepositoryTest()
        {
            // Arrange
            // get sample sims by passing in null IEnumerable into sample helper 
            IEnumerable<SimulationModel> sample_simulations = null;
            int sample_size = GetSampleSimulationsHelper(ref sample_simulations);

            // mock the Simulation repository
            var mock_sim_repo = new Mock<ISimulationRepository>();
            
            // return all of the simulations 
            mock_sim_repo.Setup(x => x.GetAllAsync()).ReturnsAsync(sample_simulations).Verifiable();

            // mock unit of work 
            var unitOfWorkMock = new Mock<IUnitOfWork>();

            // when unit of work builds a simulation repo, check that it outputs correctly
            unitOfWorkMock.Setup(x => x.SimulationRepo).Returns(mock_sim_repo.Object);


            var sim_repo = mock_sim_repo.Object;
            var unit_sim_repo = unitOfWorkMock.Object.SimulationRepo; // get a simulation repo from the mocked unitOfWork

            // call helper to Act and Assert
            VerifySimulations(sample_size, unit_sim_repo, sim_repo);
        }

        [Fact]
        public async void SimulationGetById_RepositoryTest()
        {
            // Arrange
            // get sample sims by passing in null IEnumerable into sample helper 
            IEnumerable<SimulationModel> sample_simulations = null;
            int sample_size = GetSampleSimulationsHelper(ref sample_simulations);

            // mock the Simulation repository
            var mock_sim_repo = new Mock<ISimulationRepository>();

            // By accessing any index within the list of simulations, it the repo should return the  
            // sim with the corresponding index
            int any_index = It.IsAny<int>();
            mock_sim_repo.Setup(x => x.GetByIdAsync(any_index)).ReturnsAsync(sample_simulations.ToList()[any_index]).Verifiable();

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
            Assert.NotNull(test_sims);
            Assert.NotNull(actual);

            // Compare all elements to ensure no data was lost/altered
            Assert.Equal(test_sims.Id, actual.Id);
            Assert.Equal(test_sims.simName, actual.simName);
            Assert.Equal(test_sims.simDesc, actual.simDesc);
            Assert.Equal(test_sims.gitURL, actual.gitURL);

            VerifySimulations(sample_size, unit_sim_repo, sim_repo);
        }

        [Fact]
        public async void SimulationAddAsync_RepositoryTest()

        {
            // Arrange
            // get sample sims by passing in null IEnumerable into sample helper 
            IEnumerable<SimulationModel> sample_simulations = null;
            int sample_size = GetSampleSimulationsHelper(ref sample_simulations);

            SimulationModel add_sim = new SimulationModel()
            {
                Id = 3,
                simName = "new sim",
                simDesc = "decription for new sim",
                gitURL = "https://github.com/cstainsby"
            };

            // mock the Simulation repository
            var mock_sim_repo = new Mock<ISimulationRepository>();

            // When the simulation is added there should be a one returned (one record edited)
            mock_sim_repo.Setup(x => x.AddAsync(add_sim)).ReturnsAsync(1).Verifiable(); 

            // mock unit of work 
            var unitOfWorkMock = new Mock<IUnitOfWork>();

            // when unit of work builds a simulation repo, check that it outputs correctly
            unitOfWorkMock.Setup(x => x.SimulationRepo).Returns(mock_sim_repo.Object);


            var sim_repo = mock_sim_repo.Object;
            var unit_sim_repo = unitOfWorkMock.Object.SimulationRepo; // get a simulation repo from the mocked unitOfWork

            // Act
            // find sim from mocked unitOfWork at any index
            int actual = await unit_sim_repo.AddAsync(add_sim);

            // find product from sim_repo at the same index
            int test_return_val = await sim_repo.AddAsync(add_sim);

            // get the added model from each of the repos
            // this assumes the get by Id function is working ------
            SimulationModel actual_model = await unit_sim_repo.GetByIdAsync(3);
            SimulationModel test_model = await sim_repo.GetByIdAsync(3);

            var actual_list = await unit_sim_repo.GetAllAsync();
            int actual_element_count = actual_list.ToList().Count;
            var test_list = await unit_sim_repo.GetAllAsync();
            int test_element_count = test_list.ToList().Count;

            // Assert
            // should be 1 greater than sample size due to the add 
            VerifySimulations(sample_size+1, unit_sim_repo, sim_repo);
        }

        [Fact]
        public async void SimulationRemoveAsync_RepositoryTest()
        {
            // Arrange
            // get sample sims by passing in null IEnumerable into sample helper 
            IEnumerable<SimulationModel> sample_simulations = null;
            int sample_size = GetSampleSimulationsHelper(ref sample_simulations);

            SimulationModel add_sim = new SimulationModel()
            {
                Id = 3,
                simName = "new sim",
                simDesc = "decription for new sim",
                gitURL = "https://github.com/cstainsby"
            };

            // mock the Simulation repository
            var mock_sim_repo = new Mock<ISimulationRepository>();

            // When the simulation is added there should be a one returned (one record edited)
            mock_sim_repo.Setup(x => x.AddAsync(add_sim)).ReturnsAsync(1).Verifiable();

            // mock unit of work 
            var unitOfWorkMock = new Mock<IUnitOfWork>();

            // when unit of work builds a simulation repo, check that it outputs correctly
            unitOfWorkMock.Setup(x => x.SimulationRepo).Returns(mock_sim_repo.Object);


            var sim_repo = mock_sim_repo.Object;
            var unit_sim_repo = unitOfWorkMock.Object.SimulationRepo; // get a simulation repo from the mocked unitOfWork

            // Act
            // find sim from mocked unitOfWork at any index
            int actual = await unit_sim_repo.AddAsync(add_sim);

            // find product from sim_repo at the same index
            int test_return_val = await sim_repo.AddAsync(add_sim);

            // get the added model from each of the repos
            // this assumes the get by Id function is working ------
            SimulationModel actual_model = await unit_sim_repo.GetByIdAsync(3);
            SimulationModel test_model = await sim_repo.GetByIdAsync(3);

            // Assert
            // both the test_return_val and actual should return 1
            Assert.True(test_return_val == 1);
            Assert.True(actual == 1);

            // make sure both of the recently added models aren't null
            Assert.NotNull(test_model);
            Assert.NotNull(actual_model);

            // check that they are equal
            Assert.Equal(actual_model.Id, test_model.Id);
            Assert.Equal(actual_model.simName, test_model.simName);
            Assert.Equal(actual_model.simDesc, test_model.simDesc);
            Assert.Equal(actual_model.gitURL, test_model.gitURL);
        }

        private async void VerifySimulations(int expected_size, ISimulationRepository actual, ISimulationRepository test)
        {
            // retrieve all simulations in the db
            IEnumerable<SimulationModel> actual_enumerable = await actual.GetAllAsync();
            IEnumerable<SimulationModel> test_enumerable = await test.GetAllAsync();

            // Both enumerables shouldn't be null
            Assert.NotNull(actual_enumerable);
            Assert.NotNull(test_enumerable);

            // Both collections should be the same size and match the expected 
            Assert.Equal(expected_size, actual_enumerable.Count());
            Assert.Equal(expected_size, test_enumerable.Count());

            for(int i = 0; i < expected_size; ++i)
            {
                SimulationModel actual_at_i = actual_enumerable.ElementAt(i);
                SimulationModel test_at_i = test_enumerable.ElementAt(i);

                // check that the models arent null
                Assert.NotNull(actual_at_i);
                Assert.NotNull(test_at_i);

                // check that they are equal
                Assert.Equal(actual_at_i.Id, test_at_i.Id);
                Assert.Equal(actual_at_i.simName, test_at_i.simName);
                Assert.Equal(actual_at_i.simDesc, test_at_i.simDesc);
                Assert.Equal(actual_at_i.gitURL, test_at_i.gitURL);
            }
        }

        // helper function to generate sample simulations to work with 
        private int GetSampleSimulationsHelper(ref IEnumerable<SimulationModel> sample_sims)
        {
            // sample sims is being passed in by reference, add sample simulations here
            sample_sims = new List<SimulationModel>
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
            // return the total number of sims being returned
            return sample_sims.Count();
        }
    }
}
