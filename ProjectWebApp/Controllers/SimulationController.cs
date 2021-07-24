using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using ProjectWebApp.Models;
using DataAccess;         // import the data access project 
using DataAccess.Logic;   // and its logic classes

namespace ProjectWebApp.Controllers
{
    public class SimulationController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }

        // get form
        public IActionResult Create()
        {
            return View();
        }

        // when sending data from the form use this method
        [HttpPost]
        public IActionResult Create(Simulation model)
        {
            // prevent spoofing check
            if (ModelState.IsValid)
            {
                SimulationProcessor.CreateSimulation(
                    model.Id,
                    model.simName,
                    model.simDesc,
                    model.gitURL
                );

                return View();
            }

            return RedirectToAction("Index");
        }
    }
}
