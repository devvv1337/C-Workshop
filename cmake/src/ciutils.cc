#include "ciutils/ciutils.hh"

#include <iostream>
#include <string>
#include <vector>
#include <yaml-cpp/yaml.h>

namespace CIUtils
{

    CIData parse_ci_file(const std::string& filename)
    {
        CIData data;

        YAML::Node config = YAML::LoadFile(filename);
        data.stages = config["stages"].as<std::vector<std::string>>();

        for (const auto& node : config)
        {
            // For each node in config, parse the stage and scripts using the
            // job name as first key.
            auto job = node.first.as<std::string>();

            // Skip the "stages" job as it is a special gitlab yaml node that we
            // have previously parsed.
            if (job == "stages")
                continue;

            // Retrieves the stage field of the job key.
            auto stage = config[job]["stage"];
            Job fdp = { .name = job, .stage = stage.as<std::string>() };

            data.jobs.push_back(fdp);
            auto ligne = config[job]["script"].as<std::vector<std::string>>();
            for (auto it = ligne.begin(); it != ligne.end(); it++)
            {
                data.commands.insert(
                    it.base()->substr(0, it.base()->find(" ")));
            }
            // FIXME: Create the job struct and set the name, stage, and scripts
            // variables accordingly
        }

        return data;
    }
} // namespace CIUtils
