add_executable("main" Asteriod.cpp Animation.cpp Bullet.cpp Entity.cpp ExplosionEffect.cpp GameOver.cpp Lives.cpp MainGame.cpp MainMenu.cpp Rock.cpp Score.cpp SoundEffectManager.cpp Spaceship.cpp WinScreen.cpp Asteriod.h Animation.h Bullet.h Entity.h ExplosionEffect.h GameOver.h GameState.h  Lives.h MainGame.h MainMenu.h Rock.h Score.h SoundEffectManager.h Spaceship.h WinScreen.h)
#target_link_libraries("main" sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_link_libraries("main" ${SFML_LIBRARIES})
target_compile_features(main PRIVATE cxx_range_for)

add_custom_command(
        TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/data/*
                ${CMAKE_CURRENT_BINARY_DIR} )
