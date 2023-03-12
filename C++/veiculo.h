class Veiculo {
    public:
        char *color;
        char *model;
        int year;
        double velocity;

        Veiculo();
        void xlr8(double increase);
        void stop(double decrease);
        int getVelocity();
}