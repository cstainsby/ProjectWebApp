using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using ProjectWebApp.Models;
using DataAccess;         // import the data access project 
using DataAccess.Repositories;   // and its logic classes
using DataAccess.Models;

namespace ProjectWebApp.Controllers
{
    public class SimulationController : Controller
    {
        private readonly Repository<SimulationModel> repository;
        public SimulationController(Repository<SimulationModel> repository)
        {
            this.repository = repository;
        }

        public async Task<IActionResult> Index()
        {
            ViewData["Simulation Data"] = await repository.GetAllAsync();
            return View();
        }



        // get form
        public IActionResult Create()
        {
            return View();
        }

        // when sending data from the form use this method
        [HttpPost]
        public async Task<IActionResult> Create(Simulation model)
        {
            // prevent spoofing check
            if (ModelState.IsValid)
            {
                SimulationModel data = new SimulationModel
                {
                    Id = model.Id,
                    simName = model.simName,
                    simDesc = model.simDesc,
                    gitURL = model.gitURL
                };

                return View(await repository.AddAsync(data));
            }

            return RedirectToAction("Index");
        }
    }
}
