function plot_vectors(start_points,vector)

  quiver(start_points(1,:),start_points(2,:),vector(1,:),vector(2,:),0)
  axis equal
end

