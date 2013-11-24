import("Macaroni", "ProjectTemplates", "1")
require "SimpleProject"


SimpleProject{
  group="BorderTown",
  project="Bjolt",
  version="DEV",
  libShortName="bjoltLib",
  dependencies={
    load("Macaroni", "CppStd", "2003"):Target("lib"),
    loadBoostLib("headers"),
  },
  cmakeFlags = {
    invoke=true,
    preBuildCommand = { name='cavatappi', args={'generateLess'}}
  },
};
