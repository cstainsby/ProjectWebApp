#See https://aka.ms/containerfastmode to understand how Visual Studio uses this Dockerfile to build your images for faster debugging.

FROM mcr.microsoft.com/dotnet/aspnet:5.0 AS base
WORKDIR /app
EXPOSE 80
EXPOSE 443

FROM mcr.microsoft.com/dotnet/sdk:5.0 AS build
WORKDIR /src
COPY ["ProjectWebApp/ProjectWebApp.csproj", "ProjectWebApp/"]
RUN dotnet restore "ProjectWebApp/ProjectWebApp.csproj"
COPY . .
WORKDIR "/src/ProjectWebApp"
RUN dotnet build "ProjectWebApp.csproj" -c Release -o /app/build

FROM build AS publish
RUN dotnet publish "ProjectWebApp.csproj" -c Release -o /app/publish

FROM base AS final
WORKDIR /app
COPY --from=publish /app/publish .
ENTRYPOINT ["dotnet", "ProjectWebApp.dll"]