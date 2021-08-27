using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using DataAccess.Models;
using DataAccess.Repositories;

namespace ProjectWebApp.Controllers
{
    public class ProjectMainPageController : Controller
    {
        private UnitOfWork unitOfWork;

        public ProjectMainPageController(UnitOfWork unitOfWork)
        {
            this.unitOfWork = unitOfWork;
        }

        // only accomodates simulations right now
        public async Task<IActionResult> ProjectMainPage(int modelId)
        {
            return View(await unitOfWork.SimulationRepo.GetByIdAsync(modelId));
        }
    }
}
