﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using DataAccess.Models;

namespace DataAccess.DataProcessing
{
    public static class Processor
    {
        public static SimulationProjectModel processSimulation(int Id, string simName, string simDesc, string gitURL, int dimensions)
        {
            // create new sim
            SimulationProjectModel newSim = new SimulationProjectModel
            {
                Id = Id,
                simName = simName,
                simDesc = simDesc,
                gitURL = gitURL,
                dimensions = dimensions
            };

            // setup dll and boiler plate code for given project type

            return newSim;
        }
    }
}
