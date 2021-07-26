using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace ProjectWebApp.Controllers
{
    public class SimulationPageController : Controller
    {
        public IActionResult SimulationPage()
        {
            return View();
        }

    }
}
