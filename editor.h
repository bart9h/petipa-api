namespace petipa {

class Editor {
	public:

		void run_editor (const std::string& project_file_path, void* system_context);

		data::VisualizationOptions get_visualization_options() const;
		void set_visualization_options (const data::VisualizationOptions&);

		std::vector<std::string> get_character_list() const;
		data::Character get_character (const std::string& name) const;
		std::string new_character();  // returns new character's name
		bool delete_character (const std::string&);
		bool rename_character (const std::string& old_name, const std::string& new_name);
		bool character_set_color (const std::string& name, const std::string& color);
		bool character_set_avatar (const std::string& name, const std::string& image_path);
		bool character_set_size (const std::string& name, double size);
		bool character_add_tag (const std::string& name, const std::string&* label);
		bool character_remove_tag (const std::string& name, const std::string&* label);
		bool character_set_label_display (const std::string& name, bool);
		bool character_set_path_display (const std::string& name, bool);

		std::vector<std::string> get_tag_list() const;
		data::Tag get_tag (const std::string& label) const;
		bool rename_tag (const std::string& old_label, const std::string& new_label);
		bool new_tag (const std::string& label);
		bool delete_tag (const std::string& label);
		bool set_tag_label_display (const std::string& label, bool);
		bool set_tag_path_display (const std::string& label, bool);

		data::Music get_music_definition() const;
		std::vector<std::string> get_stock_music_list() const;
		bool petipa::Editor::set_music_definition (const data::Music&);

		data::Stage get_stage_definition() const;
		std::vector<std::string> get_stage_formats() const;
		std::string get_stage_format_picture (const std::string& picture_path) const;
		bool set_stage_definition (const data::Stage&);
};

}
