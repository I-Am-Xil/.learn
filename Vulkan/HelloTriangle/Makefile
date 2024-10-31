CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
DBFLAGS = -fsanitize=address,undefined --debug

VulkanTest: main.cpp
	clang++ $(CFLAGS) -o VulkanTest main.cpp $(LDFLAGS)

.PHONY: test clean

debug:
	clang++ $(CFLAGS) -o VulkanTest main.cpp $(LDFLAGS) $(DBFLAGS)
	./VulkanTest

test: VulkanTest
	./VulkanTest

clean:
	rm -f VulkanTest
