##### Validation Layers
Vulkan itself proportionates little debuging information at runtime. This is why the Vulkan SDK proportionates an extension that gives us the posibility to attach the information we may want to our application these are the validation layers. In order for the validation layers to give us information of our application we must create a debug messenger in charge of echoing that information.


##### Vulkan Application
A vulkan application roughly has a simple workflow. One must:

- Initialize a window
- Initialize Vulkan
- Run the main loop
- Clean up its resourses


##### Objects
Some objects must be manually created with a function call of the form `vkCreateObject(...)` these must be destroyed at the end of their life.


# Graphics Pipeline
The **graphics pipeline** is the sequence of operations that take the vertices and textures of your meshes all the way to the pixels in the render targets. A simplified view of the steps would be (bullets with an asterisk are *programable* all others are *fixed-function* stages):

- Vertex/index buffer
- Input assembler
- Vertex shader*
- Tessellation*
- Geometry shader*
- Rasterization
- Fragment shader*
- Color blending
- Framebuffer


##### Input Assembler
Collects raw vertex data from the buffers and may use an index buffer to repeat elements without duplicating the vertex data.


##### Vertex Shader
Applies transformations to turn vertex positions from model space to screen space. It also passes per-vertex data down the pipeline.


##### Tessellation Shader
allows you to subdivide geometry based on certain rules to increase mesh quality.


##### Geometry shader
It's run on every primitive and can discard it ot output more primitives than came in. It's similar to the tessellation shader, but more flexiible. It's not used much in today's applicaions because the performance is subpar in most GPUs.


##### Rasterization
Discretizes the primitives into *fragments* These are the pixel elements that they fill on the framebuffer. Any fragments that fall outside the screen are discarded and the attributes outputted by the vertex shader are interpolated across the fragments. Usually the fragments that are behind other primitive fragments are also discarded here because of depth testing.


##### Fragment Shader
It's invoked for every fragment that survives and determines which framebuffers the gragments are written to and whith which color and depth values. It can use interpolated data from the vertex shaders.


##### Color Blending
Applies operations to mix different fragments that map to the same pixel in the frame buffer.


---


##### Physical Device
After creating an instance you can query for physical devices. These must have a set of properties in order to be suitable for Vulkan to use.


##### Logical Device
After selecting a physical device ypu need to create a VkDevice (logical device), where you describe which physical device features you will be using.


##### Queues 
Most opetation sperformed with Vulkan are asynchronously executed by submitting them to a VkQueue. Queues are allocated from queue families.


##### Queue Families
Each Queue family supports a specific set of operations in its queues. For example, there could be separate queue families for graphics, compute and memory transfer operations. The availability of queue families could also be used as adistinguishing factor in physical device selection.


##### Swap Chain
The **swap chain** is a collection of render targets. Its basic purpose is tu ensure that the image that we're currently rendering to is different from the one that is currenly on the screen. Every time we want to draw a frame we have to to ask the swapchain to provide us with an image to render to.


##### Image Views and Framebuffers
To draw an image acquired from the swap chain, we have to wrap it in ot a VkImageView and VkFramebuffer. An image view references a specific part of an image to be used. A frame buffer references image views that are to be used for color, depth and stencil targets. Because there could be many different images in the swap chain, we'll preemptively create an image view and framebuffer for each of them and select thr right one at draw time.


##### Render Passes
Renderpasses describe the type of images that are used during rendering operations, how they will be used, and how their contents should betreated.


##### Command Pools and Command Buffers
Since many of the operations in Vulkan, like drawing operations, need to be submitted to a queue. These operations first need to be recorded into a VkCommandBBuffer before they can be submitted. These command buffers are allocated froma aVkCommandPool that is associated with a specific queue family. To draw a triangle, we need to record a command buffer with the following operations:

- Begin the render pass
- Bind the graphics pipeline
- Draw 3 vertices
- End the render pass

Because the image in the frame buffer depends on which specific image the swap chain will give us, we need to record a command buffer for each possible image and select the right one at draw time. The alternative would be to record the command buffer again every frame, which is not as effecient.


---


##### Main Loop
- Acquire an image from the swap chain with vkAcquireNextImageKHR
- Select the appropriate command buffer for the image and execute it with vkQueueSubmit
- Return the image to the swap chain for presentation to the screen with vkQueuePresentKHR

Operations submited to queues are executed async. Therefore we have to use sync objects to ensure a correct order of execution.


















