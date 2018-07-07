# Parker Woodard
# generate_project.ps1 
# Generates a basic project from the default template. (Powershell)

# $gtest_url="https://github.com/google/googletest modules/gtest"

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
    git submodule add --name gtest https://github.com/google/googletest modules/gtest
    git submodule add --name cmake-helpers https://github.com/bijn/cmake-helpers modules/cmake-helpers

    # cat $project_name/CMakeLists.txt | %{$_-replace "Template","$project_name"}
    # cat $project_name/include/Config.hh.in | %{$_-replace "TEMPLATE","$project_name"}
}
else
{
    Write-Host "Directory $project_name already exists."
}