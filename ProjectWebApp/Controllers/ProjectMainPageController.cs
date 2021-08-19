using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using DataAccess.Models;

namespace ProjectWebApp.Controllers
{
    public class ProjectMainPageController : Controller
    {
        private AbstractProjectModel projectModel;

        public ProjectMainPageController(AbstractProjectModel projectModel)
        {
            this.projectModel = projectModel;
        }

        public IActionResult ProjectMainPage()
        {
            return View();
        }


    }
}
