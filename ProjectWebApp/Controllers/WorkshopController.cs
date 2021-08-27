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
    public class WorkshopController : NavController
    {
        public WorkshopController(UnitOfWork unitOfWork) : base(unitOfWork)
        {
        }
    }
}
