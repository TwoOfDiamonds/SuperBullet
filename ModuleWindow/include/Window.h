#pragma once

#include "../../ModuleRendering/include/Drawable.h"

#include <memory>
#include <functional>
#include <map>

#include "../../Components/include/Object.h"

namespace SuperBullet
{
	using Event = sf::Event;

	class Window
	{
	public:
		Window(
			const unsigned int width = 800,
			const unsigned int height = 600,
			const char* title = "Untitled"
		);

		~Window();

		bool IsOpen() const;
		void Close();

		void Clear();
		void Draw(const std::shared_ptr<Object> object);
		void Display();

		void PollEvents();

		using EventCallback = std::function<void()>;

		void RegisterEventCallback(Event::EventType e, EventCallback callback);
		void UnregisterEventCallback(Event::EventType e, EventCallback callback);

	private:
		sf::RenderWindow mWindow;

		using EventCallbackList = std::list<std::function<void()>>;
		std::map<Event::EventType, EventCallbackList> mCallbacks;
	};
}
