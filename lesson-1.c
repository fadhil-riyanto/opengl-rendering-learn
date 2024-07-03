#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#define viewport_width 800
#define viewport_height 600

static void defer_on_exit() {
    glfwTerminate();
}

static void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    printf("changed window at %d %d", width, height);
    glViewport(0, 0, width, height);
}

int main() {
    glfwInit();
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow *window = glfwCreateWindow(viewport_width, viewport_height, "Hello world", NULL, NULL);
    if (window == NULL) {
        perror("create window");
        glfwTerminate();
        return -1;
    }

    // // set current thread
    glfwMakeContextCurrent(window);

    // lets load the opengl versioning wrapper
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        perror("oops, init glad error");
        return -1;
    }

    // set viewport, tell opengl the size of window so opengl can render correctly
    glViewport(0, 0, viewport_width, viewport_height);

    // set the callback while users trying to resize the window
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // run the eventloop
    while(!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    defer_on_exit();
    return 0;
}

