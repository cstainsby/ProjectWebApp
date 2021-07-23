using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using ProjectWebApp.Models;

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
                return NotFound();
            }



            return View();
        }
    }
}
