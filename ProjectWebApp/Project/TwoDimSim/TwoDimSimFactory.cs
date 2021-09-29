using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using ProjectWebApp.Project.TwoDimSim.Implementation;

namespace ProjectWebApp.Project.TwoDimSim
{
    public class TwoDimSimFactory
    {
        public TwoDimSimType createTwoDimSimProject(String implementationName)
        {
            if(implementationName == "GameOfLife")
            {
                return new TwoDimSim_GameOfLife();
            }
        }
    }
}
