


```java
public class ServerExtension implements BeforeAllCallback, AfterAllCallback {
    private Server server = new Server(9000);

    public Server getServer() {
        return server;
    }

    @Override
    public void beforeAll(ExtensionContext context) throws Exception {
        server.start();
    }

    @Override
    public void afterAll(ExtensionContext context) throws Exception {
        server.stop();
    }
}

class JUnit5ServerTest {
    @RegisterExtension
    static ServerExtension extension = new ServerExtension();

    @Test
    void serverIsRunning() {
        Assertions.assertTrue(extension.getServer().isRunning());
    }
}
```