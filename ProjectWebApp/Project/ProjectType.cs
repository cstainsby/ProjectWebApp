using System;
using System.Collections;
using System.Linq;
using System.Threading.Tasks;

namespace ProjectWebApp.Project
{
    public class ProjectType<T>
    {
        protected Hashtable Settings;

        protected void setSetting(String settingName, T value)
        {
            Settings.Add(settingName, value);
        }
    }
}
