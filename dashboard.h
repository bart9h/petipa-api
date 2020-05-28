#ifndef petipa_api_editor_h_included
#define petipa_api_editor_h_included

#include <string>

namespace petipa {
namespace api {
namespace dashboard {

	struct LoginAttempt {
		bool success;
		std::time_t license_expiratio_time;
		std::string plan;
		std::string error_message;
	};

	data::LoginAttempt try_login (const std::string& user_id, const std::string& password);


	struct Project {
		std::string name;
		std::string author;
		std::time_t creation_time;
		std::time_t modification_time;
	};

	struct ProjectListSection {
		std::string label;
		std::vector<data::Project> projects;
	};

	std::string get_top_banner_content();
	std::string get_bottom_banner_content();

	std::vector<data::ProjectListSection> get_project_list_sections (bool alphabetic_order);

	bool open_new_project (void* system_context);
	bool open_project (const std::string& project_name, void* system_context);
	bool import_and_open_project (const std::string& file_path, void* system_context);
	bool copy_and_open_project (const std::string& project_name, void* system_context);
	bool rename_project (const std::string& old_name, const std::string& new_name);
	bool delete_project (const std::string& project_name);
	bool export_project (const std::string& project_name, const std::string& file_path);

}}}

#endif
