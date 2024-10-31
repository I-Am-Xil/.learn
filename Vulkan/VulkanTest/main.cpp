#include <cstdint>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>

int main(){
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << "  extensions supported\n";

    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    std::cout << "No window? It's wayland bitch\n";

    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
        //INFO: uncomment the next line if on wayland and no window gets displayed
        //its normal since wayland needs a write to the compositor buffer before\
        //creating an actual window
        //break;
    }

    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;
}
