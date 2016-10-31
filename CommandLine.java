public class CommandLine {
    private static native void execCommand0(String cmd);

    static {
        System.loadLibrary("CommandLine");
    }
    public static void execCommand(String cmd) {
      execCommand0(cmd);
    }
}
