using DataAccess.Repositories;
using Microsoft.AspNetCore.Mvc;
using ProjectWebApp.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace ProjectWebApp.Controllers
{
    public class NavController : Controller
    {
        private UnitOfWork unitOfWork;

        public NavController(UnitOfWork unitOfWork)
        {
            this.unitOfWork = unitOfWork;
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
        public async Task<IActionResult> Create(Simulation model)
        {
            // prevent spoofing check
            if (ModelState.IsValid)
            {

                ISimulationRepository simRepo = unitOfWork.SimulationRepo;

                int result = await simRepo.AddAsync(
                    model.Id,
                    model.simName,
                    model.simDesc,
                    model.gitURL,
                    model.dimensions
                    );

                unitOfWork.Save();

                if (result > 0)
                {
                    return RedirectToAction("Index", "Workshop");
                }
            }

            return StatusCode(500, new { Message = "Error Adding Item" });
        }

        public async Task<IActionResult> Remove(int Id)
        {
            ISimulationRepository simRepo = unitOfWork.SimulationRepo;

            // check if there is an element at input Id
            if (simRepo.GetByIdAsync(Id) == null)
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
