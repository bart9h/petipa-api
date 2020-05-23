namespace petipa {
namespace api {
namespace native {

	// Methods that will be called by the Editor:

	void open_visualization_options_dialog();
	void open_characters_dialog (const std::string& character_name = "");
	void open_music_dialog();
	void open_stage_dialog();

	void alert (const std::string& title, const std::string& text);
	bool confirm (const std::string& title, const std::string& text);
	std::string text_input (const std::string& title);
	void share_project (const std::string& file_path);
	void open_url (const std::string& url);

}}}


// Examples of how to use the Editor methods to set/get data:

void petipa::api::native::open_visualization_options_dialog()
{
	// getting data for gui setup
	petipa::api::editor::VisualizationOptions options = petipa::api::editor::get_visualization_options();
	std::vector<std::string> character_list = petipa::api::editor::get_character_list();
	for (const auto& name : character_list) {
		petipa::api::editor::Character character = petipa::api::editor::get_character (name);
		character.name_display_flag;
		character.path_display_flag;
	}
	std::vector<std::string> tag_list = petipa::api::editor::get_tag_list();
	for (const auto& label : tag_list) {
		petipa::api::editor::Character tag = petipa::api::editor::get_tag (label);
		tag.label_display_flag;
		tag.path_display_flag;
	}

	// applying changes
	petipa::api::editor::set_visualization_options (options);
	petipa::api::editor::set_tag_label_display_flag (label, boolean_value);
	petipa::api::editor::set_tag_path_display_flag (label, boolean_value);
	petipa::api::editor::character_set_name_display_flag (name, boolean_value);
	petipa::api::editor::character_set_path_display_flag (name, boolean_value);
}

void petipa::api::native::open_characters_dialog()
{
	// getting data for gui setup
	auto character_list = petipa::api::editor::get_character_list();
	for (const auto& name : character_list) {
		petipa::api::editor::Character character = petipa::api::editor::get_character (name);
	}
	auto tag_list = petipa::api::editor::get_tag_list();
	for (const auto& label : tag_list) {
		petipa::api::editor::Character tag = petipa::api::editor::get_tag (label);
	}

	// applying changes
	petipa::api::editor::rename_tag (old_label, new_label);
	petipa::api::editor::new_tag (label);
	petipa::api::editor::delete_tag (label);
	petipa::api::editor::rename_character (old_name, new_name);
	petipa::api::editor::new_character (name);
	petipa::api::editor::delete_character (name);
	petipa::api::editor::character_set_color (name, new_color);
	petipa::api::editor::character_set_avatar (name, new_path);
	petipa::api::editor::character_set_size (name, new_size);
	petipa::api::editor::character_add_tag (name, label);
	petipa::api::editor::character_remove_tag (name, label);
}

void petipa::api::native::open_music_dialog()
{
	// getting data for gui setup
	petipa::api::editor::Music  music_definition = petipa::api::editor::get_music_definition();
	std::vector<petipa::api::editor::Music> stock_list = petipa::api::editor::get_stock_music_list();

	// previewing music
	music_preview_play (music_title);
	music_preview_stop();

	// applying changes
	petipa::api::editor::set_music_file (const std::string& music_path);
	petipa::api::editor::set_stock_music (const std::string& music_title);
	petipa::api::editor::set_silence (unsigned int hours, unsigned int minutes, unsigned int seconds);
}

void petipa::api::native::open_stage_dialog()
{
	// getting data for gui setup
	auto stage_definition = petipa::api::editor::get_stage_definition();
	auto format_list = petipa::api::editor::get_stage_formats();
	petipa::api::editor::get_stage_format_picture (format);

	// applying changes
	petipa::api::editor::set_stage_definition (stage_definition);
}
