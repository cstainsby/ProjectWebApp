using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Autofac.Extras.Moq;
using DataAccess.Logic;
using DataAccess.Data;
using Xunit;

namespace ProjectUnitTests.Logic
{
    public class RepositoryTest
    {
        /*[Theory]
        [InlineData("FluidSim", "words w0rds words", "https://github.com/cstainsby/FluidSimulator")]
        public void CreateSimulationTest(string simName, string simDesc, string gitURL)
        {
            // the item inside the using will be automatically disposed of when brackets end
            using (var mock = AutoMock.GetLoose())
            {
                mock.Mock<SQLDataAccess>(); 
            }
        }*/

        public void CreateSimulation_ThrowsException()
        {

        }
    }
}
