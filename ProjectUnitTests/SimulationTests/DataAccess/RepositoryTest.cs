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
        private readonly ISimulationRepository sim_repo; // save the mocked sim repo in a class variable 

        public RepositoryTest()
        {
            IList<SimulationModel> simulations = GetSampleSimulations();

            // mock the Simulation repository
            var sim_repo = new Mock<ISimulationRepository>();

            // return all of the simulations 
            sim_repo.Setup(x => x.GetAllAsync()).ReturnsAsync(simulations.ToList());

            // return a simulation by Id
            sim_repo.Setup(x => x.GetByIdAsync(It.IsAny<int>())).ReturnsAsync((int i) => simulations.Where(y => y.Id == i).Single());


            this.sim_repo = sim_repo.Object;
        }

        [Fact]
        public async void ReturnAllSimulations()
        {
            // find all products
            IEnumerable<SimulationModel> test_sims = await this.sim_repo.GetAllAsync();

            Assert.True(test_sims != null);
            Assert.Equal(2, test_sims.ToList().Count);
        }

        [Fact]
        public async void ReturnSimulationById()
        {
            SimulationModel test_model = await this.sim_repo.GetByIdAsync(1);

            // check that test_model matches what is returned from the repo
            Assert.True(test_model != null);
            Assert.Equal(GetSampleSimulations().ToList()[0], test_model);

            // test the second model in the repo using the getById method 
            test_model = await this.sim_repo.GetByIdAsync(2);

            // check that test_model matches what is returned from the repo
            Assert.True(test_model != null);
            Assert.Equal(GetSampleSimulations().ToList()[1], test_model);
        }

        // helper function to generate sample simulations to work with 
        private IList<SimulationModel> GetSampleSimulations()
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
