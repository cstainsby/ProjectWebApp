
SET project_type=%1

:build
g++ -c -DPROJECT_EXPORTS %project_type%
g++ -shared -o %project_type%.dll %project_type%.o -Wl,--out-implib,lib%project_type%.a