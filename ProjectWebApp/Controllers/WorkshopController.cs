using DataAccess.Models;
using DataAccess.Repositories;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Configuration;
using ProjectWebApp.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace ProjectWebApp.Controllers
{
    public class WorkshopController : Controller
    {
        private UnitOfWork unitOfWork;

        public WorkshopController()
        {
            // build a configuration to access connection strings
            IConfiguration cnn = new ConfigurationBuilder()
                .AddJsonFile("appsettings.json")
                .Build();

            unitOfWork = new UnitOfWork(cnn.GetConnectionString("ProjectDB"));
        }

        public async Task<IActionResult> Index()
        {
            ISimulationRepository simRepo = unitOfWork.SimulationRepo;

            ViewData["Simulation Data"] = await simRepo.GetAllAsync();

            return View();
        }



        // get form
        public IActionResult Create()
        {
            return View();
        }

        // when sending data from the form use this method
        [HttpPost]
        public async Task<IActionResult> Create(Simulation simulation)
        {
            // prevent spoofing check
            if (ModelState.IsValid)
            {

                ISimulationRepository simRepo = unitOfWork.SimulationRepo;

                SimulationModel data = new SimulationModel
                {
                    Id = simulation.Id,
                    simName = simulation.simName,
                    simDesc = simulation.simDesc,
                    gitURL = simulation.gitURL
                };

                int rowsAffected = await simRepo.AddAsync(data);

                if (rowsAffected > 0)
                {
                    unitOfWork.Save();
                    return RedirectToAction("Index", "Workshop");
                }
            }

            return StatusCode(500, new { Message = "Error Adding Item" });
        }


        public async Task<IActionResult> Remove(int Id)
        {
            ISimulationRepository simRepo = unitOfWork.SimulationRepo;

            // check if there is an element at input Id
            if(simRepo.GetByIdAsync(Id) == null)
            {
                return NotFound();
            }

            int rowsAffected = await simRepo.RemoveAsync(Id);

            if (rowsAffected > 0)
            {
                unitOfWork.Save();
                return RedirectToAction("Index", "Workshop");
            }
            return StatusCode(500, new { Message = "Error Removing Error" });
        }
    }
}
