import json
# The JSON file used will depend on the current test
with open("full_config.json") as config:
	json_data = json.load(config)

json_str = json.dumps(json_data)
json_str = json_str.replace('"', '\\"')

to_write =   ""
to_write +=  "#ifndef CONFIG_PRELOAD_HPP\n"
to_write +=  "#define CONFIG_PRELOAD_HPP\n"
to_write += f"#define CONFIG_STR \"{json_str}\"\n"
to_write +=  "#endif\n"

with open("src/Config_preload.hpp", "w+") as config_output:
	config_output.write(to_write)
