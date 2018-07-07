# Parker Woodard
# generate_project.ps1 
# Generates a basic project from the default template. (Powershell)

Param
(
    [Parameter(Mandatory=$True)]
    [ValidateNotNull()]
    $project_name
)

if(!(Test-Path -Path $project_name)) 
{
    mkdir $project_name/modules
    Copy-Item template/* -Destination $project_name -Recurse
    cd $project_name

    git init
    git submodule add --name gtest `
        https://github.com/google/googletest modules/gtest
    git submodule add --name cmake-helpers `
        https://github.com/bijn/cmake-helpers modules/cmake-helpers

    (Get-Content CMakeLists.txt).replace('Template', $project_name) | Set-Content CMakeLists.txt
    (Get-Content include/Config.hh.in).replace('TEMPLATE', $project_name) | Set-Content include/Config.hh.in
}
else
{
    Write-Host "Directory $project_name already exists."
}