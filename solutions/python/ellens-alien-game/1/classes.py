"""Solution to Ellen's Alien Game exercise."""


class Alien:
    """Create an Alien object with location x_coordinate and y_coordinate.

    Attributes:
        (class) total_aliens_created (int): Total number of Alien instances.
        x_coordinate (int): Position on the x-axis.
        y_coordinate (int): Position on the y-axis.
        health (int): Number of health points.

    Methods:
        hit(): Decrement Alien health by one point.
        is_alive(): Return a boolean for if Alien is alive (if health is > 0).
        teleport(new_x_coordinate, new_y_coordinate): Move Alien object to new coordinates.
        collision_detection(other): Implementation TBD.

    """

    total_aliens_created = 0

    def __init__(self, x_coord, y_coord):
        self.x_coordinate = x_coord
        self.y_coordinate = y_coord
        self.health = 3
        self.increment_total_aliens()

    def hit(self):
        self.health -= 1

    def is_alive(self):
        if self.health > 0:
            return True
        return False

    def teleport(self, x_coord, y_coord):
        self.x_coordinate = x_coord
        self.y_coordinate = y_coord

    def collision_detection(self, other_object):
        pass

    def increment_total_aliens(self):
        Alien.total_aliens_created += 1

def new_aliens_collection(start_positions):
    return list(Alien(position[0], position[1]) for position in start_positions)

#TODO (Student): Create the new_aliens_collection() function below to call your Alien class with a list of coordinates