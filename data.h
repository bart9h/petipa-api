#include <unordered_map>

namespace petipa
{
	namespace data
	{
		enum class DisplayAllTristate { DEFAULT, ALL, NONE };
		enum class PathDisplayParts { PAST, FUTURE, ALL };
		enum class CharacterDisplayType { AVATAR, COLOR, NONE };

		struct LoginAttempt
		{
			bool success;
			std::time_t license_expiratio_time;
			std::string error_message;
		};

		struct Project
		{
			std::string name;
			std::time_t modification_time;
		};

		struct VisualizationOptions
		{
			PathDisplayParts show_path_parts;
			double path_line_width;
			double path_fade_time;
			double path_fade_opacity;
			bool show_complete_path;
			bool show_grids_and_guides;
			bool show_rulers;
			bool show_evolutions;
			CharacterDisplayType character_display_type;
			DisplayAllTristate show_all_characters_path;
			DisplayAllTristate show_all_characters_name;
			DisplayAllTristate show_all_tags_path;
			DisplayAllTristate show_all_tags_label;
		};

		struct Tag
		{
			std::string label;
			bool show_path;
			bool show_label;
		};

		struct Character
		{
			std::string name;
			bool show_path;
			bool show_name;
			std::vector<std::string> tags;
			std::string color;
		};

		struct Music
		{
			double total_seconds;
			std::string path;
			std::vector<Bars> bars_list;
		};

		struct Stage
		{
			double width, height;
			std::string format;
			std::string color;
		};
	}

}
