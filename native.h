namespace petipa {

class NativeUI {
	public:
		// Methods that will be called by the Editor:
		void open_visualization_options_dialog (petipa::Editor&);
		void open_characters_dialog (petipa::Editor&);
		void open_music_dialog (petipa::Editor&);
		void open_stage_dialog (petipa::Editor&);
		void alert (const std::string& title, const std::string& text);
		bool confirm (const std::string& title, const std::string& text);
		void share_project (const std::string& project_path);
};

}


// Example on how to use the Editor methods to set/get data:

void petipa::Frontend::open_visualization_options_dialog (petipa::Editor& editor)
{
	// getting data for gui setup
	auto options = editor.get_visualization_options();
	std::vector<std::string> character_list = editor.get_character_list();
	std::vector<std::string> tag_list = editor.get_tag_list();

	// applying changes
	editor.set_visualization_options (options);
	editor.set_tag_label_display (label, boolean_value);
	editor.set_tag_path_display (label, boolean_value);
	editor.character_set_label_display (name, boolean_value);
	editor.character_set_path_display (name, boolean_value);
}

void petipa::Frontend::open_characters_dialog (petipa::Editor& editor)
{
	// getting data for gui setup
	auto character_list = editor.get_character_list();
	for (const auto& name : character_list) {
		const auto& character = editor.get_character (name);
	}
	auto tag_list = editor.get_tag_list();
	for (const auto& label : tag_list) {
		const auto& tag = editor.get_tag (label);
	}

	// applying changes
	editor.rename_tag (old_label, new_label);
	editor.new_tag (label);
	editor.delete_tag (label);
	editor.rename_character (old_name, new_name);
	editor.new_character (name);
	editor.delete_character (name);
	editor.character_set_color (name, new_color);
	editor.character_set_avatar (name, new_path);
	editor.character_set_size (name, new_size);
	editor.character_add_tag (name, label);
	editor.character_remove_tag (name, label);
}

void petipa::Frontend::open_music_dialog (petipa::Editor& editor)
{
	// getting data for gui setup
	auto music_definition = editor.get_music_definition();
	auto stock_list = editor.get_stock_music_list();

	// applying changes
	editor.set_music_definition (music_definition);
}

void petipa::Frontend::open_stage_dialog (petipa::Editor& editor)
{
	// getting data for gui setup
	auto stage_definition = editor.get_stage_definition();
	auto format_list = editor.get_stage_formats();
	editor.get_stage_format_picture (format);

	// applying changes
	editor.set_stage_definition (stage_definition);
}
