using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace ProjectWebApp.Controllers
{
    public class ProjectMainPageController : Controller
    {
        public IActionResult ProjectMainPage()
        {
            return View();
        }


    }
}
