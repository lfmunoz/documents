



/*



*/

class ResponsiveToInterruption extends Thread {
    @Override public void run() {
        while (!Thread.currentThread().isInterrupted()) {
            System.out.println("[Interruption Responsive Thread] Alive");
        }
        System.out.println("[Interruption Responsive Thread] bye**");

    }
}

